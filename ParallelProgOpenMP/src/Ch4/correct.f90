! Example 4.6 correct version of "wrong.f90" example

    program correct 
    common /bounds/ istart, iend
    integer  iarray(10000)

    N = 10000.0
!$omp parallel private(iam, nthreads, chunk)
!$omp+ private(istart, iend)

    ! Compute the subset of iterations
    ! executed by each thread
    nthreads = omp_get_num_threads()
    iam = omp_get_thread_num()
    chunk = (N + nthreads - 1)/nthreads
    istart = iam * chunk + 1
    iend = min((iam + 1.0) * chunk, N)

    call work(iarray, istart, iend)
!$omp end parallel
    end 

    subroutine work(iarray, istart, iend)
    ! Subroutine to operate on a thread's
    ! portion of the array "iarray"
    
    integer iarray(10000)

    do i = istart, iend
        iarray(i) = i * i
    enddo 
    return 
    end 

